/*************************************************************************
    > File Name: big_data_process.cc
    > Author: anryyang
    > Mail: anryyang@gmail.com 
    > Created Time: Thu Dec  8 22:57:50 2016
 ************************************************************************/

#include<iostream>
using namespace std;

/*
 * some problems about how to find something from a big file
*/

/* Q1.
 * given a big log file of Baidu.com, each row of the log file contains an IP address and the time it accessed Baidu.com
 * Please find the IP address with highest occurrence on a given date, the memory is 2 GB.
 * 
 * Analysis:
 * 1. First, use memory mapping to read the log file, extract all IP addresses on the given date
 * 2. We have at most 2^32=4 GB IP addresses, so we cannot load all extracted results into the memory
 * 3. Instead, for each IP address extracted from the log file, apply Hash(IP)%1024, then we can divides
 *    all extracted results into 1024 small files. Each file at most contains 4 MB different IP addresses.
 * 4. For each small file, load them into memory and process them one by one, use Hash Map to 
 *    record the occurrence of each IP addresses and note down the one with highest occurrence in each small filen
 * 5. Then, we have 1024 most-frequent IP addresses from 1024 small files, sort them and we can get the answer 
*/


/* Q2.
 * Find the non-repetitive integers from 0.25 billion integers with limited memory which cannot hold 0.25 integers
 * 
 * Analysis:
 * We can use 2-Bitmap to mark whether an integer is repetitive
 * For every integer, we allocate 2 bits for it, 00 denotes non-existence, 01 denotes occurring once, 11 denotes occurring more than once
 * an integer is at most 2^32, so we need 2^32 * 2 bits space, which is exactly 1 GB
 * Scan all the integers, set its corresponding Bitmap value.
 * Scan all the integers again, find all the inetgers whose bitmap value are 00 
*/

/* Q3.
 * suppose Tencent has 4 billion non-repetitive QQ numbers (in the form of unsigned int), and all the QQ numbers are not sorted
 * given an unsigned int, how to check if it is a valid QQ number to asap
 * 
 * Analysis:
 * Use Bitmap again, 4 billion=2^32, 2^32 * 1 bit = 512 MB, 
 * each bit is used to mark existence of the corresponding unsigned int, 1 represents existence, 0 means non-existence 
*/


