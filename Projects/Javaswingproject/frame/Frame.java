package frame;
import javax.swing.JFrame;
import java.awt.Color;
import java.awt.Font;
import javax.swing.BorderFactory;
import javax.swing.ImageIcon;
import javax.swing.JLabel;
import javax.swing.border.Border;

public class Frame extends JFrame{
    public Frame()
    {
        this.setTitle("A typical student management program");
        this.setSize(1920, 1080);
        this.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        this.setVisible(true);
        ImageIcon icon = new ImageIcon("anna.png");
        this.setIconImage(icon.getImage());
        this.getContentPane().setBackground(new Color(50, 113, 168));
        this.setLayout(null);
        ImageIcon horny = new ImageIcon("WYSI.png");
        Border border = BorderFactory.createLineBorder(new Color(232, 67, 150));
        JLabel hornyLabel = new JLabel("WHEN YOU FUCKING SEE IT");
        this.add(hornyLabel);
        hornyLabel.setBounds(0,0, 250, 150);
        hornyLabel.setBorder(border);
        hornyLabel.setBackground(new Color(232, 142, 185));
        hornyLabel.setOpaque(true);
        hornyLabel.setVerticalAlignment(JLabel.CENTER);
        hornyLabel.setHorizontalAlignment(JLabel.CENTER);
        hornyLabel.setFont(new Font("MV Boli", Font.PLAIN,14));
        hornyLabel.setIcon(horny);
        hornyLabel.setHorizontalTextPosition(JLabel.CENTER);
        hornyLabel.setVerticalTextPosition(JLabel.TOP);
        hornyLabel.setForeground(Color.BLACK);
    }
    
}
