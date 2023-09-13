import kivy 
kivy.require('2.1.0')

from kivy.app import App
from kivy.uix.label import Label
from kivy.uix.gridlayout import GridLayout
from kivy.uix.textinput import TextInput
from kivy.uix.button import Button
from kivy.uix.widget import Widget
from kivy.properties import ObjectProperty

class Gameboard(Widget):
    p1_name = ObjectProperty()
    
    
    def submit(self):
        self.ids.p1_name.text = "JA GESCHAFFT"

    def revert(self):
        pass

class MainApp(App):
    def build(self):
        return Gameboard()
    
if __name__ == "__main__":
    MainApp().run()