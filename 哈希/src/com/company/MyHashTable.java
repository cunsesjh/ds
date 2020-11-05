package com.company;

import java.util.Hashtable;

public class MyHashTable {

    class Node{
        Student data;
        Node next;

        Node(Student s){
            data = s;
            next = null;
        }
    }

    Node [] table;

    MyHashTable(){
        table = new Node[11];
    }


    void put(Student s){
        //1.根据s的id找到table对应的链表
        Node a = get(s.id);
        //2.把s放到链头部
        Node newNode = new Node(null);
        newNode.data = s;
        newNode.next = a;
        //3.table[index] = newNode
        a = newNode;
        a.data.echo();
    }

    Node get(Integer id){
        //id->index
        int index = id%11;
        Node [] t = table;
        //遍历链表，查找有无对应id
        if (index < t.length){
            Node a = new Node(null);
            a = t[index];
            return a;
        }else {
            return null;
        }

    }

    void print() {
        Node[] t = table;
        int index=0;
        while(t[index] != null) {
            System.out.println("id " + t[index].data.id + ";name " + t[index].data.name);
            index++;
        }
        System.out.println();
    }

}
