package com.company;

import java.util.List;

public class Main {

    public static void main(String[] args) {
	// write your code here
        int[] prices= new int[]{7, 1, 5, 3, 6, 4};
        Solution s=new Solution();
        int sum = s.maxProfit(prices);
        System.out.printf("%d",sum);
    }
}
