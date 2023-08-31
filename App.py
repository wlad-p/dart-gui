import kivy 
kivy.require('2.1.0')

from kivy.app import App
from kivy.uix.label import Label
from kivy.uix.gridlayout import GridLayout
from kivy.uix.textinput import TextInput
from kivy.uix.button import Button

from kivy.config import Config
Config.set('graphics', 'width', '400')
#Config.set('graphics', 'height', '1280')
Config.set('graphics', 'height', '800')

class MyGrid(GridLayout):
    def __init__(self, **kwargs):
        super(MyGrid, self).__init__(**kwargs)
        self.cols = 1

        self.inside = GridLayout()
        self.inside.cols = 2


        self.inside.add_widget(Label(text="Name: "))
        self.name = TextInput(multiline=False)
        self.inside.add_widget(self.name)

        self.inside.add_widget(Label(text="Last Name: "))
        self.lastName = TextInput(multiline=False)
        self.inside.add_widget(self.lastName)

        self.inside.add_widget(Label(text="Email: "))
        self.email = TextInput(multiline=False)
        self.inside.add_widget(self.email)

        self.add_widget(self.inside)

        self.submit = Button(text="Submit", font_size=40)
        self.submit.bind(on_press=self.pressed)
        self.add_widget(self.submit)

    def pressed(self,instance):
        print("Pressed")
        name = self.name.text
        lastName = self.lastName.text
        email = self.email.text

        print("Name" + name + " Email: " + email)
        #clean 
        self.name.text = ""

class App(App):
    def build(self):
        return MyGrid()
    
if __name__ == '__main__':
    App().run()