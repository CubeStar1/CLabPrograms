import streamlit as st
import os
import base64

def list_files(directory):
    return [f for f in os.listdir(directory) if os.path.isfile(os.path.join(directory, f))]

def create_download_link(filename):
    with open(filename, "rb") as f:
        bytes = f.read()
        b64 = base64.b64encode(bytes).decode()
        href = f'<a href="data:file/octet-stream;base64,{b64}" download=\'{filename}\'>Click here to download {filename}</a>'
        return href

st.title('C Programming Lab')
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
    selected_file = st.selectbox('Select a program', files)

    with st.container(border=True):
        program_description = program_descriptions.get(selected_file, "No description available")
        st.markdown(f'**Description:** {program_description}')

if st.button('Download Program'):
    href = create_download_link(os.path.join(directory, selected_file))
    st.markdown(href, unsafe_allow_html=True)