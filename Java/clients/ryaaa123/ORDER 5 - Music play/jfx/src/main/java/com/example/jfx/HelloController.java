package com.example.jfx;

import javafx.fxml.FXML;
import javafx.scene.control.Label;
import javafx.scene.media.*;
public class HelloController {

    String name = "song.mp3";
    Media song = new Media(name);
    MediaPlayer player = new MediaPlayer(song);
player.play();
}