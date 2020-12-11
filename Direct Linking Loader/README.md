# AIM:
***
## To write a "C" program to implement Direct-Linking Loader in System Software Lab.

***

## ALGORITHM for Pass 1:
***
1.Get the PROGADDR from the user
2.Initiate CSADDR with value of PROGADDR
3.Read header record from object program
4.Store the length of the control section in CSLTH
5.Search the ESTAB for control section name
(i)If found display an error message
(ii)Otherwise, insert the control section name with CSADDR into ESTAB
6.Read the next input record
7.If the record type is END goto step 10
8.If the record type is not D goto step 6
9.Search the ESTAB for symbol names given in D record.
(i)If found display an error message
(ii)Otherwise, insert the symbol into ESTAB with the sum of CSADDR and indicated address and goto step 6.
10.Add CSLTH to CSADDR.
11.If end of file is reached, Exit. Otherwise goto step 3.

***

## ALGORITHM for Pass 2:
***
1.Read the header record from object program.
2.Get the CSADDR for the correct control section from ESTAB.
3.Read next input record.
4.If the record type is END, go to step 8.
5.If the record type is ‘T’, place the object code in location which is sum of CSADDR and specified address.
6.If the record type is ‘M’ search the ESTAB for symbol table.
   (i)If found add or subtract symbol value at location CSADDR + specified Address.
   (ii)Otherwise display error message.
7.Read next input record and go to step 4.
8.If end of file is reached,Exit.Otherwise go to step 1.