import kivy 
kivy.require('2.1.0')

from kivy.app import App
from kivy.uix.label import Label
from kivy.uix.gridlayout import GridLayout
from kivy.uix.textinput import TextInput
from kivy.uix.button import Button
from kivy.uix.widget import Widget
from kivy.properties import ObjectProperty

class Keyboard(Widget):
    name = ObjectProperty(None)
    email = ObjectProperty(None)

    def submit(self):
        pass

    def revert(self):
        pass

class GameBoard(Widget):
    pass

class DartCounter(App):
    def build(self):
        return Keyboard()
    
if __name__ == "__main__":
    DartCounter().run()