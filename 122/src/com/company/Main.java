package com.company;

import java.util.Stack;

public class Main {

    public static void main(String[] args) {
	// write your code here
        int[] a = new int[10];
        for (int i=0; i<10; i++){
            a[i]=i;
        }
        for (int i=0; i<10; i++){
            System.out.println(a[i]);
        }

        Stack<Integer> s = new Stack<Integer>();
        int sum = 0;
        for (int i=0; i<a.length; i++){
            if (s.isEmpty())
                s.push(a[i]);
            else{
                if (a[i]>s.peek())
                    sum+=a[i]-s.peek();
                s.push(a[i]);
            }
            System.out.println(sum);

        }

    }
}
