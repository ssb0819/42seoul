#!/bin/bash
string1="The bonus part will only be assessed if the mandatory part is
PERFECT. Perfect means the mandatory part has been integrally done
and works without malfunctioning. If you have not passed ALL the
mandatory requirements, your bonus part will not be evaluated at all.
The bonus part will only be assessed if the mandatory part is
PERFECT. Perfect means the mandatory part has been integrally done
and works without malfunctioning. If you have not passed ALL the
mandatory requirements, your bonus part will not be evaluated at all.
The bonus part will only be assessed if the mandatory part is
PERFECT. Perfect means the mandatory part has been integrally done
and works without malfunctioning. If you have not passed ALL the
mandatory requirements, your bonus part will not be evaluated at all.
The bonus part will only be assessed if the mandatory part is
PERFECT. Perfect means the mandatory part has been integrally done
and works without malfunctioning. If you have not passed ALL the
mandatory requirements, your bonus part will not be evaluated at all."

string2="The cis-3-Hexen-1-ol, also known as (Z)-3-hexen-1-ol and leaf alcohol, is a colorless oily
liquid with an intense grassy-green odor of freshly cut green grass and leaves.
It is produced in small amounts by most plants and it acts as an attractant to many
predatory insects. cis-3-Hexen-1-ol is a very important aroma compound that is used in
fruit and vegetable flavors and in perfumes. The yearly production is about 30 tonnes.
The cis-3-Hexen-1-ol, also known as (Z)-3-hexen-1-ol and leaf alcohol, is a colorless oily
liquid with an intense grassy-green odor of freshly cut green grass and leaves.
It is produced in small amounts by most plants and it acts as an attractant to many
predatory insects. cis-3-Hexen-1-ol is a very important aroma compound that is used in
fruit and vegetable flavors and in perfumes. The yearly production is about 30 tonnes.
The cis-3-Hexen-1-ol, also known as (Z)-3-hexen-1-ol and leaf alcohol, is a colorless oily
liquid with an intense grassy-green odor of freshly cut green grass and leaves.
It is produced in small amounts by most plants and it acts as an attractant to many
predatory insects. cis-3-Hexen-1-ol is a very important aroma compound that is used in
fruit and vegetable flavors and in perfumes. The yearly production is about 30 tonnes.
The cis-3-Hexen-1-ol, also known as (Z)-3-hexen-1-ol and leaf alcohol, is a colorless oily
liquid with an intense grassy-green odor of freshly cut green grass and leaves.
It is produced in small amounts by most plants and it acts as an attractant to many
predatory insects. cis-3-Hexen-1-ol is a very important aroma compound that is used in
fruit and vegetable flavors and in perfumes. The yearly production is about 30 tonnes.
The cis-3-Hexen-1-ol, also known as (Z)-3-hexen-1-ol and leaf alcohol, is a colorless oily
liquid with an intense grassy-green odor of freshly cut green grass and leaves.
It is produced in small amounts by most plants and it acts as an attractant to many
predatory insects. cis-3-Hexen-1-ol is a very important aroma compound that is used in
fruit and vegetable flavors and in perfumes.
The yearly production is about 30 tonnes."

echo "Test Minitalk.......Server PID : $1"
echo "============================="
echo "send first string (1055 characters - 1055 bytes)"
time ./client $1 "$string1"
echo "============================="
echo "send second string (2144 characters - 2144 bytes)"
time ./client $1 "$string2"
