import os
from conans import ConanFile, python_requires, CMake
conan_tools = python_requires("conan-tools/[>=1.0.0]@includeos/stable")

class DiskbuilderConan(ConanFile):
    settings="os_build","arch_build"
    name = "diskbuilder"
    version = conan_tools.git_get_semver()
    license = "Apache-2.0"
    description = "A tool to create an IncludeOS binary filesystem image"
    scm = {
        "type" : "git",
        "url" : "auto",
        "subfolder": ".",
        "revision" : "auto"
    }
    generators='cmake'
    no_copy_source=True
    default_user="includeos"
    default_channel="latest"

    def _cmake_configure(self):
        cmake=CMake(self)
        cmake.configure(source_folder=self.source_folder)
        return cmake

    def build(self):
        cmake=self._cmake_configure()
        cmake.build()

    def package(self):
        cmake=self._cmake_configure()
        cmake.install()

    def package_info(self):
        self.env_info.path.append((os.path.join(self.package_folder, "bin")))

    def deploy(self):
        self.copy("*", dst="bin",src="bin")
