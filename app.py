import streamlit as st
import os
import base64
import streamlit_ace
from streamlit_ace import st_ace
import subprocess

def list_files(directory):
    return [f for f in os.listdir(directory) if os.path.isfile(os.path.join(directory, f))]

def create_download_link(filename):
    with open(filename, "rb") as f:
        bytes = f.read()
        b64 = base64.b64encode(bytes).decode()
        href = f'<a href="data:file/octet-stream;base64,{b64}" download=\'{filename}\'>Click here to download {filename}</a>'
        return href

def read_file(filename):
    with open(filename, 'r') as f:
        return f.read()

def run_code(code):
    with open('temp.c', 'w') as f:
        f.write(code)
    compile_process = subprocess.run(['gcc', 'temp.c', '-o', 'temp'], text=True, capture_output=True)
    if compile_process.returncode != 0:
        return compile_process.stderr
    run_process = subprocess.run(['./temp'], text=True, capture_output=True)
    return run_process.stdout

st.title('C Programming Lab Course')
st.markdown("Here you can download the code for different programs.")

directory = 'programs'
files = list_files(directory)

# Dictionary with program descriptions
program_descriptions = {
    'binary_search.c': 'This program performs binary search on an array of integers.',
    'bubble_sort.c': 'This program sorts an array of integers using the bubble sort algorithm.',
    'linear_search.c': 'This program performs linear search on an array of integers.',
    'matrix_operations.c': 'This program performs various matrix operations.',
    'quadratic.c': 'This program solves quadratic equations.',
    'selection_sort.c': 'This program sorts an array of integers using the selection sort algorithm.',
}


with st.container(border=True):
    st.write('Select a program from the dropdown below to view the code and run it.')
    selected_file = st.selectbox('Select a program', files)

    with st.container(border=True):
        program_description = program_descriptions.get(selected_file, 'No description available')
        st.markdown(f'**Program Description**: {program_description}', unsafe_allow_html=True)


    if st.button('Download Program', use_container_width=True):
        href = create_download_link(os.path.join(directory, selected_file))
        st.markdown(href, unsafe_allow_html=True)

# Read the contents of the selected file
code_raw = read_file(os.path.join(directory, selected_file))


with st.container(border=True):
    st.write('## Code Editor')
    st.write('You can edit the code here and run it using the button below.')
# Add a code editor
    code = st_ace(
        value=code_raw,
        placeholder="Write your code here...",
        language="c",
        theme="monokai",
        keybinding="vscode",
        font_size=14,
        tab_size=4,
    )

# Add a button to run the code
if st.button('Run Code'):
    output = run_code(code)
    st.code(output)