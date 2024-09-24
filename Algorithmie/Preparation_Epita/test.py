# Dictionaries store mappings from keys to values
empty_dict = {}
# Here is a prefilled dictionary
filled_dict = {"one": 1, "two": 2, "three": 3}

# Note keys for dictionaries have to be immutable types. This is to ensure that
# the key can be converted to a constant hash value for quick look-ups.
# Immutable types include ints, floats, strings, tuples.
#invalid_dict = {[1,2,3]: "123"}  # => Yield a TypeError: unhashable type: 'list'
valid_dict = {(1,2,3):[1,2,3]}   # Values can be of any type, however.
# print(valid_dict)
# print(valid_dict[(1,2,3)])
# keys = list(valid_dict.values())
# print(filled_dict.get("four",5))
# print(filled_dict)
# print(filled_dict.setdefault("four",4))
# print(filled_dict.get("four",5))
# print(filled_dict.setdefault("four",6))
# print(filled_dict)

print({"a": 1, **{"b": 2,"a":2, "c":'a'}})  # => {'a': 1, 'b': 2}
print({"a": 1, **{"a": "c"}})  # => {'a': 2}
valid_set = {(1,), 1}
print(valid_set)