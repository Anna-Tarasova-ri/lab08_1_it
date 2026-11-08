#include "pch.h"
#include "CppUnitTest.h"
#include <cstring>
#include "../PR8_1_it/pr8_1_it.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

// Допоміжна функція: копіює source у змінюваний буфер, викликає Change
// і перевіряє, що і результат функції, і параметр дорівнюють expected.
static void CheckChange(const char* source, const char* expected)
{
    char s[101];
    memcpy(s, source, strlen(source) + 1);

    char* r = Change(s);

    Assert::AreEqual(expected, (const char*)r);   // результат функції
    Assert::AreEqual(expected, (const char*)s);   // параметр

    delete[] r;
}

namespace Lab8_1_Iterative
{
    TEST_CLASS(PR8_1_it)
    {
    public:
        // ---- Count ----
        TEST_METHOD(Count_EmptyString) { Assert::AreEqual(0, Count("")); }
        TEST_METHOD(Count_NoOccurrences) { Assert::AreEqual(0, Count("hello world")); }
        TEST_METHOD(Count_PartialWord) { Assert::AreEqual(0, Count("whil")); }
        TEST_METHOD(Count_UpperCase) { Assert::AreEqual(0, Count("While WHILE")); }
        TEST_METHOD(Count_OnlyWhile) { Assert::AreEqual(1, Count("while")); }
        TEST_METHOD(Count_InsideText) { Assert::AreEqual(1, Count("a while b")); }
        TEST_METHOD(Count_InsideWord) { Assert::AreEqual(1, Count("xwhiley")); }
        TEST_METHOD(Count_Several) { Assert::AreEqual(3, Count("while a while b while")); }
        TEST_METHOD(Count_Adjacent) { Assert::AreEqual(2, Count("whilewhile")); }
        TEST_METHOD(Count_Mixed) { Assert::AreEqual(5, Count("while a while whilewhile xwhile whil")); }

        // ---- Change ----
        TEST_METHOD(Change_EmptyString) { CheckChange("", ""); }
        TEST_METHOD(Change_NoOccurrences) { CheckChange("hello world", "hello world"); }
        TEST_METHOD(Change_PartialWord) { CheckChange("whil", "whil"); }
        TEST_METHOD(Change_UpperCase) { CheckChange("While WHILE", "While WHILE"); }
        TEST_METHOD(Change_OnlyWhile) { CheckChange("while", "***"); }
        TEST_METHOD(Change_AtStart) { CheckChange("while end", "*** end"); }
        TEST_METHOD(Change_AtEnd) { CheckChange("start while", "start ***"); }
        TEST_METHOD(Change_InsideWord) { CheckChange("xwhiley", "x***y"); }
        TEST_METHOD(Change_Several) { CheckChange("while a while b while", "*** a *** b ***"); }
        TEST_METHOD(Change_Adjacent) { CheckChange("whilewhile", "******"); }
        TEST_METHOD(Change_Mixed) { CheckChange("while a while whilewhile xwhile whil", "*** a *** ****** x*** whil"); }
    };
}