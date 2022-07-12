package frame;
import javax.swing.*;
import java.awt.Color;
import java.awt.*;


import javax.swing.border.Border;

public class Frame extends JFrame{
    public Frame()
    {
        this.setTitle("A typical student management program");
        this.setSize(1920, 1080);
        this.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        this.setVisible(true);
        ImageIcon icon1 = new ImageIcon("kyouani.jpg");
        this.setIconImage(icon1.getImage());
        this.getContentPane().setBackground(new Color(50, 113, 168));
        this.setLayout(null);

        Border numPanelBorder;
        numPanelBorder = BorderFactory.createLineBorder(Color.green, 5);
        ImageIcon icon = new ImageIcon("src\\assignment\\redo\\Icons\\missing.png");
        JLabel label = new JLabel();
        JTextField textField = new JTextField();
        JLabel warningLabel = new JLabel();
        
        JPanel getNumberPanel;
        getNumberPanel = new JPanel();
        getNumberPanel.setLayout(new BorderLayout());
        getNumberPanel.setBounds(500, 400, 500, 200);
        getNumberPanel.setBorder(numPanelBorder);
        getNumberPanel.add(label);
        getNumberPanel.add(warningLabel);

        label.setIcon(icon);
        label.setBounds(5,5,495,190);
        label.setVerticalAlignment(JLabel.CENTER);
        label.setHorizontalAlignment(JLabel.CENTER);

        JButton button = new JButton("Next");
        button.setSize(60, 30);
        button.setBounds(217, 140, 60, 30);

        label.add(button);
        label.add(textField);

        textField.setSize(90, 40);
        textField.setBounds(202, 90, 90, 40);
        textField.setFont(new Font("MV Boli", Font.PLAIN,20));
        textField.setHorizontalAlignment(JLabel.CENTER);
        textField.setForeground(Color.green);
        textField.setBackground(Color.black);
        textField.setCaretColor(Color.white);
        textField.setBorder(numPanelBorder);

        warningLabel.setFont(new Font("consolus", Font.BOLD, 15));
        warningLabel.setForeground(Color.red);
        warningLabel.setBackground(Color.black);
        warningLabel.setText("INVALID INPUT, MUST BE A POSITIVE INTEGER");
        warningLabel.setBounds(296, 100, 90, 40);

    

        this.add(getNumberPanel);
    }
    
}
