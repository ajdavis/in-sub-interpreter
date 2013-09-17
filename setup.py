from distutils.core import setup, Extension

in_sub_interpreter = Extension(
    'in_sub_interpreter',
    sources=['in_sub_interpreter.c'])

setup(
    name='InSubInterpreter',
    version='1.0',
    description='Determine if code is running in a Python sub interpreter',
    ext_modules=[in_sub_interpreter])
