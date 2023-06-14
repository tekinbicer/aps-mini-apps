#!/usr/bin/python
# -*- coding: UTF-8 -*-

import sys
import zmq
import time
from threading import Thread


class Poller(Thread):

  def __init__(self, id, topic):
    super().__init__()
    self.id = id
    self.topic = topic

  def run(self):
    print('start poller {}'.format(self.id))
    subscriber = context.socket(zmq.SUB)
    subscriber.connect("tcp://127.0.0.1:50001")
    #subscriber.setsockopt_string(zmq.SUBSCRIBE, self.topic)
    self.loop = True
    while self.loop:
      message = subscriber.recv()
      print('poller {}: {}'.format(self.id, message))

  def stop(self):
    self.loop = False

context = zmq.Context()

poller1 = Poller(1, 'NASDA')
poller1.start()

time.sleep(60*5)

poller1.stop()

sys.exit(0)
