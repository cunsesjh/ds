package com.company;

public class Main {

    public static void main(String[] args) {
        // write your code here
        MyHashTable table = new MyHashTable();
        Student e1 = new Student(1,"zhangsan");
        table.get(e1.id);
        table.put(e1);
        table.print();

        Student e2 = new Student(12,"lisi");
        table.get(e2.id);
        table.put(e2);
        table.print();
    }
}