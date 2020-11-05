package com.company;

import java.util.HashMap;

class Solution {
    public boolean wordPattern(String pattern, String str) {
        HashMap<Character, Character> s = new HashMap<>();
        String[] str1 = str.split(" ");
        if (pattern.length() != str1.length)
            return false;
        for (int i; i<pattern.length(); i++){
            
        }
    }
}