# AIM:

## To write a "C" program to implement Direct-Linking Loader in System Software Lab.

***

## ALGORITHM for Pass 1:
1.Get the PROGADDR from the user.<BR>
2.Initiate CSADDR with value of PROGADDR.<BR>
3.Read header record from object program.<BR>
4.Store the length of the control section in CSLTH.<BR>
5.Search the ESTAB for control section name. <BR>
(i)If found display an error message.<BR>
(ii)Otherwise, insert the control section name with CSADDR into ESTAB.<BR>
6.Read the next input record.<BR>
7.If the record type is END goto step 10.<BR>
8.If the record type is not D goto step 6.<BR>
9.Search the ESTAB for symbol names given in D record.<BR>
(i)If found display an error message.<BR>
(ii)Otherwise, insert the symbol into ESTAB with the sum of CSADDR and indicated address and goto step 6.<BR>
10.Add CSLTH to CSADDR.<BR>
11.If end of file is reached, Exit. Otherwise goto step 3.<BR>

***
## ALGORITHM for Pass 2:

1.Read the header record from object program.<BR>
2.Get the CSADDR for the correct control section from ESTAB.<BR>
3.Read next input record.<BR>
4.If the record type is END, go to step 8.<BR>
5.If the record type is ‘T’, place the object code in location which is sum of CSADDR and specified address.<BR>
6.If the record type is ‘M’ search the ESTAB for symbol table.<BR>
   (i)If found add or subtract symbol value at location CSADDR + specified Address.<BR>
   (ii)Otherwise display error message.<BR>
7.Read next input record and go to step 4.<BR>
8.If end of file is reached,Exit.Otherwise go to step 1.<BR>
