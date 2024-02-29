package ru.nsu.dsavenko.examples.mvc.swing.controller;

import ru.nsu.dsavenko.examples.mvc.model.Model;

import javax.swing.text.BadLocationException;
import javax.swing.text.Document;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.event.WindowAdapter;
import java.awt.event.WindowEvent;

public class SwingController extends WindowAdapter implements ActionListener {
    public static final String SUBMIT_ANSWER = "submitAnswer";

    private final Model model;
    private final Document inputModel;

    public SwingController(Model model, Document inputModel) {
        this.model = model;
        this.inputModel = inputModel;
    }

    @Override
    public void actionPerformed(ActionEvent e) {
        try {
            int x = Integer.parseInt(inputModel.getText(0, inputModel.getLength()));
            model.setUserAnswer(x);
        } catch (NumberFormatException ex) {
            model.setWrongInput();
        } catch (BadLocationException ex) {
            throw new RuntimeException(ex);
        }
    }

    @Override
    public void windowClosing(WindowEvent e) {
        try {
            model.close();
        } catch (InterruptedException ex) {
            throw new RuntimeException(ex);
        }
        e.getWindow().setVisible(false);
        e.getWindow().dispose();
    }

    public Document getInputModel() {
        return inputModel;
    }
}
