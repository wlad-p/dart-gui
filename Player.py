class Player:

    def __init__(self, name):
        self.name = name 
        self.points = 501

    def score(self, points):
        self.points = self.points - points
        return self.points
    
    def getPoints(self):
        return self.points