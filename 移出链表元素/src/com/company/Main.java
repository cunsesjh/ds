package com.company;

public class Main {

    public static void main(String[] args) {
	// write your code here
        Solution s = new Solution();
        int [] gas = {1,2,3,4,5};
        int [] cost = {3,4,5,1,2};
        int result = s.gas(5,gas,cost);
        System.out.printf("%d",result);
        System.out.println();

    }
}
