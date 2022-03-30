package de.limago;

import java.awt.*;
import java.awt.event.*;

public class Main extends Frame {


    public Main()  {

        setSize(300, 300);
        Button b = new Button("Drück mich");

        b.addActionListener(e->ausgabe());
        addWindowListener(new MyWindowListener());
        add(b);
    }

    public static void main(String[] args) {
	    new Main().setVisible(true);
    }


    private void ausgabe() {
        System.out.println("Drück mich");
    }

    private void beenden() {
        dispose();
    }
   private class MyActionListener implements ActionListener{

       @Override
       public void actionPerformed(ActionEvent e) {
           ausgabe();
       }
   }

   class MyWindowListener extends WindowAdapter {
       @Override
       public void windowClosing(WindowEvent e) {
           dispose();
       }
   }
}
