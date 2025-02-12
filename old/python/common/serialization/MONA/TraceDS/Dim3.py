# automatically generated by the FlatBuffers compiler, do not modify

# namespace: TraceDS

import flatbuffers

class Dim3(object):
    __slots__ = ['_tab']

    # Dim3
    def Init(self, buf, pos):
        self._tab = flatbuffers.table.Table(buf, pos)

    # Dim3
    def Z(self): return self._tab.Get(flatbuffers.number_types.Int32Flags, self._tab.Pos + flatbuffers.number_types.UOffsetTFlags.py_type(0))
    # Dim3
    def Y(self): return self._tab.Get(flatbuffers.number_types.Int32Flags, self._tab.Pos + flatbuffers.number_types.UOffsetTFlags.py_type(4))
    # Dim3
    def X(self): return self._tab.Get(flatbuffers.number_types.Int32Flags, self._tab.Pos + flatbuffers.number_types.UOffsetTFlags.py_type(8))

def CreateDim3(builder, z, y, x):
    builder.Prep(4, 12)
    builder.PrependInt32(x)
    builder.PrependInt32(y)
    builder.PrependInt32(z)
    return builder.Offset()
