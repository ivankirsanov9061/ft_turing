#include "ParseArguments.h"
#include "HelpArgument.h"

#include <gtest/gtest.h>

TEST(IsHelpArgumentGiven, without_arguments)
{
    const char *argv[]={
            "./turing",
    };

    EXPECT_EQ(IsHelpArgumentGiven(1, argv), false);
}

TEST(IsHelpArgumentGiven, with_hel_without_p)
{
    const char *argv[]={
            "./turing",
            "--hel",
    };

    EXPECT_EQ(IsHelpArgumentGiven(2, argv), false);
}

TEST(IsHelpArgumentGiven, with_one_help_flag)
{
    const char *argv[]={
            "./turing",
            "--help"
    };

    EXPECT_EQ(IsHelpArgumentGiven(2, argv), true);
}

TEST(IsHelpArgumentGiven, with_one_h_flag)
{
    const char *argv[]={
            "./turing",
            "-h"
    };

    EXPECT_EQ(IsHelpArgumentGiven(2, argv), true);
}

TEST(IsHelpArgumentGiven, with_help_and_h_flags)
{
    const char *argv[]={
            "./turing",
            "--help",
            "-h"
    };

    EXPECT_EQ(IsHelpArgumentGiven(3, argv), true);
}

TEST(IsHelpArgumentGiven, any_flags_with_help)
{
    const char *argv[]={
            "./turing",
            "flag_a",
            "flag_b",
            "--help",
            "flag_c",
    };

    EXPECT_EQ(IsHelpArgumentGiven(5, argv), true);
}
