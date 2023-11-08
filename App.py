#from DataFetcher import DataFetcher

from kivy.app import App
from kivy.uix.boxlayout import BoxLayout
from kivy.uix.label import Label
from kivy.uix.button import Button
from kivy.uix.widget import Widget
from kivy.core.window import Window
from kivy.uix.image import Image
from kivy.clock import Clock


#Window.fullscreen = 'auto'

class MyBoxLayout(BoxLayout):
    def __init__(self, **kwargs):
        super(MyBoxLayout, self).__init__(**kwargs)
        self.orientation='vertical'
        self.add_widget(Label(text="Pupsechki in Kroatien"))
        self.add_widget(Image(source='photos/current.jpg'))
        self.add_widget(Label(text="Alo der beste hier steht dIe Beschreibung was ich so tohles hier mache in Kroatien damit sie bissen. Habe hier auch das Better hinzugefugt damit sie sehen konnen haha der beste <3"))

        Clock.schedule_interval(self.update, 60)

    def update():
        dat

class MyApp(App):
    def build(self):
        return MyBoxLayout()

if __name__ == '__main__':
    MyApp().run()