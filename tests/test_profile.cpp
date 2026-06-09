#include <gtest/gtest.h>
#include "profile.h"

// these tests check if the profile is valid, checks the name and age specifically
TEST(ProfileValidity, InvalidWhenNameEmpty) {
    Profile p("", 18, false, "", 0.0, 0.0);
    EXPECT_FALSE(p.isValid());
}

TEST(ProfileValidity, InvalidWhenAgeNegative) {
    Profile p("Krish", -1, false, "", 0.0, 0.0);
    EXPECT_FALSE(p.isValid());
}

TEST(ProfileValidity, ValidProfile) {
    Profile p("Krish", 18, false, "", 0.0, 0.0);
    EXPECT_TRUE(p.isValid());
}

// checking if the password verification behaves correctly depending on if the password is enabled
TEST(ProfilePassword, PasswordDisabledAlwaysReturnsTrue) {
    Profile p("Krish", 18, false, "secret", 0.0, 0.0);

    EXPECT_TRUE(p.verifyPassword("secret"));
    EXPECT_TRUE(p.verifyPassword("wrong"));
    EXPECT_TRUE(p.verifyPassword(""));
}

TEST(ProfilePassword, PasswordEnabledCorrectPassword) {
    // correct password should pass
    Profile p("Krish", 18, true, "secret", 0.0, 0.0);

    EXPECT_TRUE(p.verifyPassword("secret"));
}

TEST(ProfilePassword, PasswordEnabledWrongPassword) {
    // wrong password should be rejected
    Profile p("Krish", 18, true, "secret", 0.0, 0.0);

    EXPECT_FALSE(p.verifyPassword("wrong"));
    EXPECT_FALSE(p.verifyPassword(""));
}


// profiles loaded from the json file use the same password instead of rehashing it
TEST(ProfileFromStore, DoesNotRehashStoredPassword) {
    // create a normal profile (hash happens here)
    Profile original("Krish", 18, true, "secret", 0.0, 0.0);
    QString storedHash = original.getPassHash();

    // load profile using fromStore (hash should be reused, not rehashed)
    Profile loaded = Profile::fromStore("Krish", 18, true, storedHash, 0.0, 0.0);

    EXPECT_EQ(loaded.getPassHash(), storedHash);
}

// verifying that entering the correct password allows you to log in after loading data
TEST(ProfileFromStore, LoadedProfileVerifiesPasswordCorrectly) {
    Profile original("Krish", 18, true, "secret", 0.0, 0.0);
    QString storedHash = original.getPassHash();

    Profile loaded = Profile::fromStore("Krish", 18, true, storedHash, 0.0, 0.0);

    EXPECT_TRUE(loaded.verifyPassword("secret"));
    EXPECT_FALSE(loaded.verifyPassword("wrong"));
}


// check that the password toggling updates behavior
TEST(ProfilePassword, TogglePasswordProtection) {
    Profile p("Krish", 18, false, "secret", 0.0, 0.0);

    // initially disabled
    EXPECT_TRUE(p.verifyPassword("anything"));

    // enabling protection
    p.togglePasswordProtect(true);
    EXPECT_TRUE(p.verifyPassword("secret"));
    EXPECT_FALSE(p.verifyPassword("wrong"));

    // disabling again
    p.togglePasswordProtect(false);
    EXPECT_TRUE(p.verifyPassword("wrong"));
}
