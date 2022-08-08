import glob

env = Environment(CCFLAGS=["--std=c++20", "-g"], CPPPATH='/opt/homebrew/Cellar/botan/2.18.2/include/botan-2')
lib = ['botan-2']
for i in glob.glob('*.cpp'):
    env.Program(i[0:-4] + '.bin', i, LIBS=lib, LIBPATH = ['/opt/homebrew/Cellar/botan/2.18.2/lib'])
