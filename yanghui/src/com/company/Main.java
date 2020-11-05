package com.company;

import java.util.List;

public class Main {

    public static void main(String[] args) {
	// write your code here
        Solution s=new Solution();
        List<List<Integer>> r = s.generate(7);
        for (int i=0; i< r.size();i++){
            List<Integer> line = r.get(i);
            for (int j=0; j<r.size()-line.size();j++)
                System.out.printf(" ");
            for (int j=0; j<line.size();j++)
                System.out.printf(" %2d", line.get(j));
            System.out.println();
        }
    }
}
