package ru.nsu.dsavenko.examples.mvc.view;

import ru.nsu.dsavenko.examples.mvc.model.Model;
import ru.nsu.dsavenko.examples.mvc.model.ModelListener;

public class View implements ModelListener {
    private final Model model;

    public View(Model model) {
        this.model = model;
        onModelChanged();
    }

    @Override
    public void onModelChanged() {
        switch (model.getState()) {
            case NO_ANSWER:
                StringBuilder sb = new StringBuilder();
                sb.append("\nEnter the sum (or -1 to exit). You have ");
                sb.append(model.getTimeout() / 1000);
                sb.append(" seconds.\n");
                sb.append(model.getA());
                sb.append(" + ");
                sb.append(model.getB());
                sb.append(" = ");
                System.out.print(sb);
                break;
            case USER_RIGHT:
                System.out.println("Correct!");
                break;
            case USER_WRONG:
                System.out.println("Incorrect!");
                break;
            case INPUT_MISMATCH:
                System.out.println("Not a number!");
        }
    }
}
