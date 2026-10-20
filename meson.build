project(
	'berzerk',
	'cpp',
	default_options: {
		'buildtype': 'debug',
		'b_ndebug': 'if-release',
		'cpp_std': 'c++20',
		'warning_level': '3',
	},
	meson_version: '>=1.2.0',
	version: '0.0.0',
)

buildtype = get_option('buildtype')
if buildtype == 'release'
	overrides = {'werror': true}
else
	overrides = {}
endif

sdl3_dep = dependency('sdl3')

incdir = include_directories('include')
sources = [
	'src/main.cpp',
	'src/bullet.cpp',
	'src/game.cpp',
	'src/map.cpp',
	'src/player.cpp',
	'src/render.cpp'
]

executable(
	'berzerk',
	sources: sources,
	include_directories: incdir,
	dependencies: [sdl3_dep],
	override_options: overrides,
)
