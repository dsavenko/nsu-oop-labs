package ru.nsu.dsavenko.examples.mvc.model;

public class Ticker extends Thread {

    private final Model model;

    public Ticker(Model model) {
        this.model = model;
    }

    @Override
    public void run() {
        while (!isInterrupted()) {
            try {
                Thread.sleep(model.getTimeout());
                model.generate();
            } catch (InterruptedException e) {
                break;
            }
        }
    }
}
