package ru.nsu.dsavenko.examples.mvc.swing.view;

import ru.nsu.dsavenko.examples.mvc.model.Model;

import javax.swing.SwingUtilities;

public class SwingMain {
    public static void main(String[] args) {
        Model model = new Model();
        SwingUtilities.invokeLater(() -> {
            MainWindow mainWindow = new MainWindow(model);
            mainWindow.setVisible(true);
        });
    }
}
