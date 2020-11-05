package com.company;

import java.util.ArrayList;
import java.util.Stack;

class Solution {
    public int maxProfit(int[] prices) {
        int sum=0;
        int cha=0;
        Stack<Integer> s= new Stack<>();
        s.push(prices[0]);
        for (int i=1; i<prices.length; i++){
            cha=prices[i]-prices[i-1];
            if (cha>0)
                sum+=cha;
            s.push(prices[i]);
        }
        return sum;
    }
}