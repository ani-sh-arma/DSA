import os


def remove_exe_files(directory):
    """
    Recursively remove all .exe files in the given directory and its subdirectories.
    """
    for root, _, files in os.walk(directory):
        for file in files:
            if (
                file.endswith(".exe")
                | file.endswith(".class")
                | file.endswith("tempCodeRunnerFile.cpp")
                | file.endswith("tempCodeRunnerFile.py")
            ):
                file_path = os.path.join(root, file)
                try:
                    os.remove(file_path)
                    print(f"Deleted: {file_path}")
                except Exception as e:
                    print(f"Failed to delete {file_path}: {e}")


if __name__ == "__main__":
    current_directory = os.getcwd()
    remove_exe_files(current_directory)
