import kivy 
kivy.require('2.1.0')

from kivy.app import App
from kivy.uix.label import Label

from kivy.config import Config
Config.set('graphics', 'width', '400')
Config.set('graphics', 'height', '1280')

class App(App):
    def build(self):
        return Label(text="Hello")
    
if __name__ == '__main__':
    App().run()