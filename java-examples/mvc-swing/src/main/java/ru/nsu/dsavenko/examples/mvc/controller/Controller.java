package ru.nsu.dsavenko.examples.mvc.controller;

import ru.nsu.dsavenko.examples.mvc.model.Model;

import java.util.InputMismatchException;
import java.util.Scanner;

public class Controller {

    private final Scanner scanner = new Scanner(System.in);
    private final Model model;

    public Controller(Model model) {
        this.model = model;
    }

    public void readUserAnswers() {
        int x = 0;
        while (-1 != x) {
            try {
                x = scanner.nextInt();
                model.setUserAnswer(x);
            } catch (InputMismatchException e) {
                model.setWrongInput();
                scanner.next();
            }
        }
    }
}
