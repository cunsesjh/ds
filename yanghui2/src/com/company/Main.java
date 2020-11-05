package com.company;

import java.util.List;

public class Main {

    public static void main(String[] args) {
        // write your code here
        Solution s=new Solution();
        List<Integer> r = s.getRow(3);
        for (int i=0; i< r.size();i++){
            System.out.printf("%4d", r.get(i));
        }
        System.out.println();
    }
}
