package com.company;

public class MyLinkedList {

    class Node{
        Integer data;
        Node next;
    }

    int size;
    Node head;

    MyLinkedList(){
        head = null;
        size = 0;
    }

    Node getIndex(int index){
        Node l = head;
        while (index > 0){
            l = l.next;
            index--;
        }
        return l;
    }

    void print(){
        Node t = head;
        while (t != null){
            System.out.print(t.data + " ");
            t=t.next;
        }
        System.out.println();
    }

    void add(Integer value,int index){
        if (index > size || index < 0){
            //超出链表的边界
            System.out.println("index" + index + "out of " + size);
        }else {
            //在index之前的一个节点插入
            Node newNode = new Node();
            newNode.data = value;
            if (index == 0){
                newNode.next = head;
                head = newNode;
            }else {
                //1.找到前一个节点
                Node pre = getIndex(index -1);
                //2.newNode.next = pre.next
                newNode.next = pre.next;
                //3.pre.next = newNode
                pre.next = newNode;

            }
            size++;
        }

    }

    Integer remove(int index) {
        if (index < 0 || index > size) {
            // 超出链表的边界
            System.out.println("index " + index + " out of bound " + size);
            // 此处不规范，应当抛出异常
            return -1;
        } else {
            Integer r;
            if (index == 0) {
                r = head.data;
                head = head.next;
            } else {
                Node pre = get(index-1);
                r = pre.next.data;
                pre.next = pre.next.next;
            }
            size--;
            return r;
        }
    }


}
