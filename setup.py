from setuptools import setup, Extension

levenshtein = Extension("levenshtein", sources=["levenshtein.c"])

setup(name = "levenshtein",
		version = '0.1',
		description = 'edit_distance extension for Python',
		ext_modules = [levenshtein])
