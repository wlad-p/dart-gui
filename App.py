from kivy.app import App
from kivy.uix.boxlayout import BoxLayout
from kivy.uix.label import Label
from kivy.uix.button import Button
from kivy.uix.widget import Widget
from kivy.core.window import Window

Window.fullscreen = 'auto'

class PlayerCard(Widget):
    pass

class Keyboard(Widget):
    pass

class MyApp(App):
    def build(self):
        parent = Widget()
        self.playerCard = PlayerCard()
        parent.add_widget(self.playerCard)
        self.keyboard = Keyboard()
        parent.add_widget(self.keyboard)
        return parent
    
if __name__ == '__main__':
    MyApp().run()
