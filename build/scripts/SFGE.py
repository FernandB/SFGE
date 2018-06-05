print("Python SFGE")


class Vector2f:
    def __init__(self):
        self.x = 0
        self.y = 0


class Timer:
    def __init__(self, time, period):
        pass
    
    def reset(self):
        pass
    
    def update(self, dt):
        pass
    
    def get_current(self):
        pass
    
    def get_current_time(self):
        pass
    
    def is_over(self):
        pass


class Module:
    def init(self):
        pass
    
    def update(self, dt):
        pass
    
    def destroy(self):
        pass


class SpriteManager:
    pass


class TextureManager:
    pass    


class GraphicsManager(Module):
    pass


class Engine:
    def __init__(self):
        self.modules = []


class GameObject:
    def __init__(self):
        self.components = []


class Component:
    def __init__(self, game_object, name):
        self.gameObject = game_object
        self.name = name
    
    def update(self, dt):
        pass

class Transform(Component):
    def __init__(self, game_object):
        pass


class KeyboardManager:

    def is_key_held(self, key):
        pass

    def is_key_down(self, key):
        pass

    def is_key_up(self, key):
        pass

class InputManager:
    keyboard = KeyboardManager()

engine = Engine()
input_manager = InputManager()
    