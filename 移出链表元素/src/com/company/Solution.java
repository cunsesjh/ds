package com.company;

import java.util.HashSet;
import java.util.LinkedList;
import java.util.Queue;
import java.util.Stack;

class Solution {
    public int gas(int N,int [] gas,int [] cost) {

        for (int k=0; k<N; k++){
            int count=0;
            int roil=0;
            for (int i=k; i<N+k; i++){
                int c=0;
                if (i>=N)
                    c=i-N;
                else
                    c=i;

                roil = roil+gas[c];
                roil = roil-cost[c];
                if (roil<0)
                    break;
                else
                    count++;
                if (count == N)
                    return i-N+1;
            }
        }

        return -1;
    }

}
