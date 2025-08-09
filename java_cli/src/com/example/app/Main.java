package com.example.app;

public class Main {
    public static void main(String[] args) {
        String who = (args.length > 0) ? args[0] : "Mahdi";
        String msg = Core.greet(who);
        System.out.println(msg);
    }
}
