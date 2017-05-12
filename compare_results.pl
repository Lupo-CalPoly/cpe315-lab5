#!/usr/bin/perl

use strict;
use Test::Number::Delta within => 0.05, tests => 1;

my $goldfile = shift;
my $tfile = shift;
my @gold;
my @result;

# open file
open(GOLD, "$goldfile" ) or die("Unable to open $goldfile");
open(TEST, "$tfile" ) or die("Unable to open $tfile");

# read file into an array
while (<GOLD>) {
  chomp;
  push @gold, split(/ /,$_); 
}

while (<TEST>) {
  chomp;
  push @result, split(/ /,$_);
}


delta_ok( \@gold, \@result, 'Compare @gold and @result.');

# close file 
close(GOLD);
close(TEST);
