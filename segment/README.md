# Segmentation Study

Yes, paging is the primary mechanism for memory management in modern operating systems, but what's up with segmentation? Segmentation is kind of just quietly lurking in the background.

The GDT has a limited number of entries for segment descriptors.
It must be the case that some segment descriptors are referenced by the segment selectors of multiple processes. Otherwise the GDT would get full too quickly. I'm getting the feeling that the descriptor for the code segment (CS) in the GDT is referenced by most processes, but is this also the case for all of the other segments? What happens to the segment selectors when using threading (especially FS)? What happens if an application changes FS or GS? Let's find out.
