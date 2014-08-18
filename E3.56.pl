#!/bin/perl
use strict;
use warnings;

main();

sub main
{
    my ($input, @str, %result) = qw{};

    print "Please input your string:\n";
    $input = <STDIN>;

    chomp($input);

    @str = split('', $input);

    for my $i (@str)
    {
        if (not exists $result{"$i"})
        {
            $result{"$i"} = 1;
        }
        else
        {
            $result{"$i"} += 1;
        }
    }

    for my $key (sort keys %result)
    {
        print $key . ": " .  $result{"$key"} ."\n";
    }

    return;
}