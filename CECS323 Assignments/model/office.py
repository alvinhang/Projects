class Office:
    def __init__(self, officecode, city, state, country):
        self.officecode = officecode
        self.city = city
        self.state = state
        self.country = country

    def __str__(self):
        return f"{self.city}, {self.state} {self.country} ({self.officecode})"