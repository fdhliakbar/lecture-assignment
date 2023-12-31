package main;

import javax.swing.*;
import java.awt.Dimension;
import javax.swing.JPanel;
import java.awt.Color;
public class GamePanel extends JPanel {
    // SCREEN SETTINGS
    final int originalTileSize = 16; // 16x16 tile
    final int scale = 3; // 16 x 3(scale) = 48
    final int tileSize = originalTileSize * scale; // 48x48 tile
    final int maxScreenCol = 16;
    final int maxScreenRow = 12;
    final int screenWidth = tileSize * maxScreenCol; // 768 pixels
    final int screenHeight = tileSize * maxScreenRow; // 576 pixels

    public GamePanel() {
        this.setPreferredSize(new Dimension(screenWi, screenHeight));
        this.setBackground(Color.black);
        this.setDoubleBuffered(true);
    }
}
