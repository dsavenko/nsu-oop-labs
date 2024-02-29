package ru.nsu.dsavenko.examples.mvc.swing.view;

import ru.nsu.dsavenko.examples.mvc.model.Model;
import ru.nsu.dsavenko.examples.mvc.model.ModelListener;
import ru.nsu.dsavenko.examples.mvc.swing.controller.SwingController;

import javax.swing.Box;
import javax.swing.BoxLayout;
import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JPanel;
import javax.swing.JTextField;
import javax.swing.SwingUtilities;
import javax.swing.border.EmptyBorder;
import javax.swing.text.Document;
import javax.swing.text.PlainDocument;
import java.awt.BorderLayout;
import java.awt.Container;
import java.awt.Dimension;

public class MainWindow extends JFrame implements ModelListener {
    private static final int PADDING = 10;

    private final Model model;

    private JLabel questionLabel;
    private JTextField answerField;
    private JLabel checkLabel;

    public MainWindow(Model model) {
        super("Swing MVC example");
        setResizable(false);
        this.model = model;
        Document inputModel = new PlainDocument();
        SwingController controller = new SwingController(model, inputModel);

        setDefaultCloseOperation(DO_NOTHING_ON_CLOSE);
        addWindowListener(controller);

        JPanel pane = new JPanel(new BorderLayout(PADDING, PADDING));
        pane.setBorder(new EmptyBorder(PADDING, PADDING, PADDING, PADDING));

        checkLabel = new JLabel("Enter the answer and click OK.");
        pane.add(checkLabel, BorderLayout.PAGE_START);
        pane.add(createQuestionBox(controller), BorderLayout.CENTER);
        add(pane);
        pack();
        setLocationRelativeTo(null);

        model.setListener(this);
        onModelChanged();
    }

    @Override
    public void onModelChanged() {
        SwingUtilities.invokeLater(() -> {
            switch (model.getState()) {
                case NO_ANSWER:
                    questionLabel.setText(model.getA() + " + " + model.getB() + " = ");
                    break;
                case USER_RIGHT:
                    checkLabel.setText("Correct!");
                    break;
                case USER_WRONG:
                    checkLabel.setText("Incorrect!");
                    break;
                case INPUT_MISMATCH:
                    checkLabel.setText("Not a number!");
            }
        });
    }

    private void addHorizontalPadding(Container container) {
        container.add(Box.createRigidArea(new Dimension(PADDING, 0)));
    }

    private JPanel createQuestionBox(SwingController controller) {
        JPanel panel = new JPanel();
        panel.setLayout(new BoxLayout(panel, BoxLayout.X_AXIS));

        addHorizontalPadding(panel);
        questionLabel = new JLabel("Question");
        panel.add(questionLabel);

        addHorizontalPadding(panel);
        answerField = new JTextField(controller.getInputModel(), "", 6);
        answerField.setMinimumSize(answerField.getPreferredSize());
        answerField.setMaximumSize(answerField.getPreferredSize());
        panel.add(answerField);

        addHorizontalPadding(panel);
        JButton okButton = new JButton("OK");
        okButton.setActionCommand(SwingController.SUBMIT_ANSWER);
        okButton.addActionListener(controller);
        panel.add(okButton);

        addHorizontalPadding(panel);

        return panel;
    }
}
