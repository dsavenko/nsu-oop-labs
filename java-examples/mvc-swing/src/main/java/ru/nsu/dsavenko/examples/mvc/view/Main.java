package ru.nsu.dsavenko.examples.mvc.view;

import ru.nsu.dsavenko.examples.mvc.controller.Controller;
import ru.nsu.dsavenko.examples.mvc.model.Model;

public class Main {
    public static void main(String[] args) throws InterruptedException {
        try (Model model = new Model()) {
            Controller controller = new Controller(model);
            View view = new View(model);
            model.setListener(view);
            controller.readUserAnswers();
        }
    }
}
