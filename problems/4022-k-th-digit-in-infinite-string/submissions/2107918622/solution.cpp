class Solution {
public:
    int kthDigit(long long k) {
        if (k<=9) return (int)k;
        k=k-9;
        int d=2; 
        long long firstNo=10;
        while(true){
            long long numingrp=9*firstNo;
            long long digingrp=numingrp*d;
            if (k<=digingrp) break;
            k=k-digingrp;
            d++;
            firstNo*=10;
        }
        long long numidx=(k-1)/d;
        int digpos=(k-1)%d;
        long long blockstart=firstNo/10;
        long long block=blockstart+numidx/10;
        long long posinblock=numidx%10;

        long long number;
        if (block%2==0){
            number=10*block+posinblock;
        } else {
            number=10* block+(9-posinblock);
        }
        string s=to_string(number);
        return s[digpos]-'0';
    }
};